#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct usb_audio_term {int type; int id; scalar_t__ name; } ;
struct mixer_build {int dummy; } ;
struct iterm_name_combo {int type; char* name; } ;

/* Variables and functions */
#define  UAC1_EXTENSION_UNIT 131 
#define  UAC1_PROCESSING_UNIT 130 
#define  UAC_MIXER_UNIT 129 
#define  UAC_SELECTOR_UNIT 128 
 struct iterm_name_combo* iterm_names ; 
 int snd_usb_copy_string_desc (struct mixer_build*,scalar_t__,unsigned char*,int) ; 
 int sprintf (unsigned char*,char*,int) ; 
 int /*<<< orphan*/  strcpy (unsigned char*,char*) ; 
 int strlen (char*) ; 

__attribute__((used)) static int get_term_name(struct mixer_build *state, struct usb_audio_term *iterm,
			 unsigned char *name, int maxlen, int term_only)
{
	struct iterm_name_combo *names;

	if (iterm->name)
		return snd_usb_copy_string_desc(state, iterm->name, name, maxlen);

	/* virtual type - not a real terminal */
	if (iterm->type >> 16) {
		if (term_only)
			return 0;
		switch (iterm->type >> 16) {
		case UAC_SELECTOR_UNIT:
			strcpy(name, "Selector"); return 8;
		case UAC1_PROCESSING_UNIT:
			strcpy(name, "Process Unit"); return 12;
		case UAC1_EXTENSION_UNIT:
			strcpy(name, "Ext Unit"); return 8;
		case UAC_MIXER_UNIT:
			strcpy(name, "Mixer"); return 5;
		default:
			return sprintf(name, "Unit %d", iterm->id);
		}
	}

	switch (iterm->type & 0xff00) {
	case 0x0100:
		strcpy(name, "PCM"); return 3;
	case 0x0200:
		strcpy(name, "Mic"); return 3;
	case 0x0400:
		strcpy(name, "Headset"); return 7;
	case 0x0500:
		strcpy(name, "Phone"); return 5;
	}

	for (names = iterm_names; names->type; names++)
		if (names->type == iterm->type) {
			strcpy(name, names->name);
			return strlen(names->name);
		}
	return 0;
}