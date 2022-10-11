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
// $hash=dc8fd6995ca7b6ec38887cba0da5330b2dd22e9e$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_NAVIGATION_ENTRY_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_NAVIGATION_ENTRY_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_navigation_entry_capi.h"
#include "include/cef_navigation_entry.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefNavigationEntryCToCpp
    : public CefCToCppRefCounted<CefNavigationEntryCToCpp,
                                 CefNavigationEntry,
                                 cef_navigation_entry_t> {
 public:
  CefNavigationEntryCToCpp();
  virtual ~CefNavigationEntryCToCpp();

  // CefNavigationEntry methods.
  bool IsValid() override;
  CefString GetURL() override;
  CefString GetDisplayURL() override;
  CefString GetOriginalURL() override;
  CefString GetTitle() override;
  TransitionType GetTransitionType() override;
  bool HasPostData() override;
  CefBaseTime GetCompletionTime() override;
  int GetHttpStatusCode() override;
  CefRefPtr<CefSSLStatus> GetSSLStatus() override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_NAVIGATION_ENTRY_CTOCPP_H_
