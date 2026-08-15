/*
* Copyright 2013 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <android-base/strings.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

namespace android {
    namespace init {
        void property_override(char const prop[], char const value[])
        {
            prop_info *pi;

            pi = (prop_info*) __system_property_find(prop);
            if (pi)
                __system_property_update(pi, value, strlen(value));
            else
                __system_property_add(prop, strlen(prop), value, strlen(value));
        }

        void vendor_load_properties()
        {
            std::string bootloader = android::base::GetProperty("ro.bootloader", "unknown");

            if (bootloader.find("A300F") == 0) {
                property_override("ro.product.model", "SM-A300F");
                property_override("ro.vendor.product.model", "SM-A300F");
            } else if (bootloader.find("A300H") == 0) {
                property_override("ro.product.model", "SM-A300H");
                property_override("ro.vendor.product.model", "SM-A300H");
            } else if (bootloader.find("A300M") == 0) {
                property_override("ro.product.model", "SM-A300M");
                property_override("ro.vendor.product.model", "SM-A300M");
            } else if (bootloader.find("A300FU") == 0) {
                property_override("ro.product.model", "SM-A300FU");
                property_override("ro.vendor.product.model", "SM-A300FU");
            } else if (bootloader.find("A300G") == 0) {
                property_override("ro.product.model", "SM-A300G");
                property_override("ro.vendor.product.model", "SM-A300G");
			} else if (bootloader.find("A300Y") == 0) {
                property_override("ro.product.model", "SM-A300Y");
                property_override("ro.vendor.product.model", "SM-A300Y");
            } else if (bootloader.find("A300YX") == 0) {
                property_override("ro.product.model", "SM-A300YX");
                property_override("ro.vendor.product.model", "SM-A300YX");
			}
        }
    }
}
