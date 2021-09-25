#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/lineage_landtoni.mk

COMMON_LUNCH_CHOICES := \
    lineage_landtoni-user \
    lineage_landtoni-userdebug \
    lineage_landtoni-eng

PRODUCT_MAKEFILES += \
    $(LOCAL_DIR)/cherish_landtoni.mk

COMMON_LUNCH_CHOICES += \
    cherish_landtoni-user \
    cherish_landtoni-userdebug \
    cherish_landtoni-eng
