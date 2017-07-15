/*
 * Copyright (C) 2017 The LineageOS Project
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

#include <sys/mman.h>

#define MMAP2_SHIFT 12 // 2**12 == 4096

extern "C" {

void *__mmap2(void*, size_t, int, int, int, size_t);

void *mmap65(void* addr, size_t size, int prot, int flags, int fd, off64_t offset) {
    return __mmap2(addr, size, prot, flags, fd, offset >> MMAP2_SHIFT);
}

}
