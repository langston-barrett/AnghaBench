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
typedef  int /*<<< orphan*/  LPWSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  IInternetProtocolInfo ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  IInternetProtocolInfo_ParseUrl (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IInternetProtocolInfo_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PARSE_PATH_FROM_URL ; 
 int /*<<< orphan*/  PathCreateFromUrlW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugstr_w (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * get_protocol_info (int /*<<< orphan*/ ) ; 

__attribute__((used)) static HRESULT parse_path_from_url(LPCWSTR url, DWORD flags, LPWSTR result, DWORD size, DWORD *rsize)
{
    IInternetProtocolInfo *protocol_info;
    DWORD prsize;
    HRESULT hres;

    TRACE("(%s %08x %p %d %p)\n", debugstr_w(url), flags, result, size, rsize);

    protocol_info = get_protocol_info(url);

    if(protocol_info) {
        hres = IInternetProtocolInfo_ParseUrl(protocol_info, url, PARSE_PATH_FROM_URL,
                flags, result, size, rsize, 0);
        IInternetProtocolInfo_Release(protocol_info);
        if(SUCCEEDED(hres))
            return hres;
    }

    prsize = size;
    hres = PathCreateFromUrlW(url, result, &prsize, 0);

    if(rsize)
        *rsize = prsize;
    return hres;
}