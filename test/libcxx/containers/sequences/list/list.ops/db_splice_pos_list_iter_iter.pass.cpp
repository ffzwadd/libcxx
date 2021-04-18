//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <list>

// void splice(const_iterator position, list& x, iterator first, iterator last);

// UNSUPPORTED: libcxx-no-debug-mode

// ADDITIONAL_COMPILE_FLAGS: -D_LIBCPP_DEBUG=1

#include <list>

#include "test_macros.h"
#include "debug_macros.h"

int main(int, char**)
{
    {
      std::list<int> v1(3);
      std::list<int> v2(3);
      TEST_LIBCPP_ASSERT_FAILURE(
          v1.splice(v1.begin(), v2, v2.begin(), v1.end()),
          "list::splice(iterator, list, iterator, iterator) called with third iterator not referring to the list argument");
    }

  return 0;
}
