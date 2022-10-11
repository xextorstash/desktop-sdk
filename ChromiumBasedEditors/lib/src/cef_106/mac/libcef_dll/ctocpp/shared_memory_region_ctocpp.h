// Copyright (c) 2022 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=d477b2660e271bbdc4d6e8f866f006b84f13e50d$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_SHARED_MEMORY_REGION_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_SHARED_MEMORY_REGION_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_shared_memory_region_capi.h"
#include "include/cef_shared_memory_region.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefSharedMemoryRegionCToCpp
    : public CefCToCppRefCounted<CefSharedMemoryRegionCToCpp,
                                 CefSharedMemoryRegion,
                                 cef_shared_memory_region_t> {
 public:
  CefSharedMemoryRegionCToCpp();
  virtual ~CefSharedMemoryRegionCToCpp();

  // CefSharedMemoryRegion methods.
  bool IsValid() override;
  size_t Size() override;
  const void* Memory() override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_SHARED_MEMORY_REGION_CTOCPP_H_
