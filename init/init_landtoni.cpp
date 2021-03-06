/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>

#include <libinit_msm8937.h>

static const variant_info_t land_info = {
    .brand = "Xiaomi",
    .device = "land",
    .marketname = "",
    .model = "Redmi 3S",
    .build_description = "land-user 6.0.1 MMB29M V10.2.2.0.MALMIXM release-keys",
    .build_fingerprint = "Xiaomi/land/land:6.0.1/MMB29M/V10.2.2.0.MALMIXM:user/release-keys",
};

static const variant_info_t santoni_info = {
    .brand = "Xiaomi",
    .device = "santoni",
    .marketname = "",
    .model = "Redmi 4X",
    .build_description = "santoni-user 7.1.2 N2G47H V11.0.2.0.NAMMIXM release-keys",
    .build_fingerprint = "Xiaomi/santoni/santoni:7.1.2/N2G47H/V11.0.2.0.NAMMIXM:user/release-keys",
};

static void determine_device_land(const std::string &proc_cmdline)
{
    set_variant_props(land_info);

    if (proc_cmdline.find("S88537AB1") != proc_cmdline.npos)
        set_ro_build_prop("model", "Redmi 3X", true);

    if (proc_cmdline.find("S88537AC1") != proc_cmdline.npos || proc_cmdline.find("S88537EC1") != proc_cmdline.npos)
        property_override("ro.vendor.fingerprint.supported", "0");
    else
        property_override("ro.vendor.fingerprint.supported", "2");
}

static void determine_device_santoni(const std::string &proc_cmdline)
{
    set_variant_props(santoni_info);

    if (proc_cmdline.find("S88536CA2") != proc_cmdline.npos)
        set_ro_build_prop("model", "Redmi 4", true);

    property_override("ro.vendor.fingerprint.supported", "2");
}

static void determine_device()
{
    std::string proc_cmdline;
    android::base::ReadFileToString("/proc/cmdline", &proc_cmdline, true);

    if (proc_cmdline.find("S88537") != proc_cmdline.npos)
        determine_device_land(proc_cmdline);
    else if (proc_cmdline.find("S88536") != proc_cmdline.npos)
        determine_device_santoni(proc_cmdline);
}

void vendor_load_properties() {
    determine_device();
    set_dalvik_heap_size();
#ifdef LIBINIT_MSM8937_MODS
    load_mods();
#endif
}
