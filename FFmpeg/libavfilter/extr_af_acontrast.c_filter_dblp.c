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

/* Variables and functions */
 double const M_PI_2 ; 
 float sin (double) ; 

__attribute__((used)) static void filter_dblp(void **d, const void **s,
                        int nb_samples, int channels,
                        float contrast)
{
    int n, c;

    for (c = 0; c < channels; c++) {
        const double *src = s[c];
        double *dst = d[c];

        for (n = 0; n < nb_samples; n++) {
            double d = src[n] * M_PI_2;

            dst[n] = sin(d + contrast * sin(d * 4));
        }
    }
}