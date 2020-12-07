//===-- HostThreadWindows.h -------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef lldb_Host_windows_HostThreadWindows_h_
#define lldb_Host_windows_HostThreadWindows_h_

#include "lldb/Host/HostNativeThreadBase.h"

#include "llvm/ADT/SmallString.h"

namespace lldb_private {

class HostThreadWindows : public HostNativeThreadBase {
  DISALLOW_COPY_AND_ASSIGN(HostThreadWindows);

public:
  HostThreadWindows();
  HostThreadWindows(lldb::thread_t thread);
  virtual ~HostThreadWindows();

  void SetOwnsHandle(bool owns);

  virtual Status Join(lldb::thread_result_t *result);
  virtual Status Cancel();
  virtual void Reset();
  virtual bool EqualsThread(lldb::thread_t thread) const;

  lldb::tid_t GetThreadId() const;

private:
  bool m_owns_handle;
};
}

#endif
