#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * descriptor; } ;
struct TYPE_5__ {TYPE_1__ base; } ;
typedef  TYPE_2__ WiFiScanResult ;
typedef  int /*<<< orphan*/  ProtobufCMessage ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 size_t protobuf_c_message_get_packed_size (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  wi_fi_scan_result__descriptor ; 

size_t wi_fi_scan_result__get_packed_size
                     (const WiFiScanResult *message)
{
  assert(message->base.descriptor == &wi_fi_scan_result__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}