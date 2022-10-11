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
// $hash=a8a10af1258edd37dbb8d079a10943070c1e9c4c$
//

#include "libcef_dll/cpptoc/dev_tools_message_observer_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK dev_tools_message_observer_on_dev_tools_message(
    struct _cef_dev_tools_message_observer_t* self,
    cef_browser_t* browser,
    const void* message,
    size_t message_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: message; type: simple_byaddr
  DCHECK(message);
  if (!message)
    return 0;

  // Execute
  bool _retval = CefDevToolsMessageObserverCppToC::Get(self)->OnDevToolsMessage(
      CefBrowserCToCpp::Wrap(browser), message, message_size);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK dev_tools_message_observer_on_dev_tools_method_result(
    struct _cef_dev_tools_message_observer_t* self,
    cef_browser_t* browser,
    int message_id,
    int success,
    const void* result,
    size_t result_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: result

  // Execute
  CefDevToolsMessageObserverCppToC::Get(self)->OnDevToolsMethodResult(
      CefBrowserCToCpp::Wrap(browser), message_id, success ? true : false,
      result, result_size);
}

void CEF_CALLBACK dev_tools_message_observer_on_dev_tools_event(
    struct _cef_dev_tools_message_observer_t* self,
    cef_browser_t* browser,
    const cef_string_t* method,
    const void* params,
    size_t params_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: method; type: string_byref_const
  DCHECK(method);
  if (!method)
    return;
  // Unverified params: params

  // Execute
  CefDevToolsMessageObserverCppToC::Get(self)->OnDevToolsEvent(
      CefBrowserCToCpp::Wrap(browser), CefString(method), params, params_size);
}

void CEF_CALLBACK dev_tools_message_observer_on_dev_tools_agent_attached(
    struct _cef_dev_tools_message_observer_t* self,
    cef_browser_t* browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefDevToolsMessageObserverCppToC::Get(self)->OnDevToolsAgentAttached(
      CefBrowserCToCpp::Wrap(browser));
}

void CEF_CALLBACK dev_tools_message_observer_on_dev_tools_agent_detached(
    struct _cef_dev_tools_message_observer_t* self,
    cef_browser_t* browser) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefDevToolsMessageObserverCppToC::Get(self)->OnDevToolsAgentDetached(
      CefBrowserCToCpp::Wrap(browser));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefDevToolsMessageObserverCppToC::CefDevToolsMessageObserverCppToC() {
  GetStruct()->on_dev_tools_message =
      dev_tools_message_observer_on_dev_tools_message;
  GetStruct()->on_dev_tools_method_result =
      dev_tools_message_observer_on_dev_tools_method_result;
  GetStruct()->on_dev_tools_event =
      dev_tools_message_observer_on_dev_tools_event;
  GetStruct()->on_dev_tools_agent_attached =
      dev_tools_message_observer_on_dev_tools_agent_attached;
  GetStruct()->on_dev_tools_agent_detached =
      dev_tools_message_observer_on_dev_tools_agent_detached;
}

// DESTRUCTOR - Do not edit by hand.

CefDevToolsMessageObserverCppToC::~CefDevToolsMessageObserverCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefDevToolsMessageObserver>
CefCppToCRefCounted<CefDevToolsMessageObserverCppToC,
                    CefDevToolsMessageObserver,
                    cef_dev_tools_message_observer_t>::
    UnwrapDerived(CefWrapperType type, cef_dev_tools_message_observer_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType
    CefCppToCRefCounted<CefDevToolsMessageObserverCppToC,
                        CefDevToolsMessageObserver,
                        cef_dev_tools_message_observer_t>::kWrapperType =
        WT_DEV_TOOLS_MESSAGE_OBSERVER;
