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

            if (bootloader.find("J510FN") == 0) {
                property_override("ro.product.model", "SM-J510FN");
                property_override("ro.vendor.product.model", "SM-J510FN");
            } else if (bootloader.find("J510FQ") == 0) {
                property_override("ro.product.model", "SM-J510FQ");
                property_override("ro.vendor.product.model", "SM-J510FQ");
            } else if (bootloader.find("J510GN") == 0) {
                property_override("ro.product.model", "SM-J510GN");
                property_override("ro.vendor.product.model", "SM-J510GN");
            } else if (bootloader.find("J510MN") == 0) {
                property_override("ro.product.model", "SM-J510MN");
                property_override("ro.vendor.product.model", "SM-J510MN");
            } else if (bootloader.find("J510UN") == 0) {
                property_override("ro.product.model", "SM-J510UN");
                property_override("ro.vendor.product.model", "SM-J510UN");
            }
        }
    }
}
