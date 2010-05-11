//===----------------------------------------------------------------------===//
//
// ΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚThe LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <tuple>

// template <class... Types> class tuple;

// template <class U1, class U2>
//   tuple& operator=(pair<U1, U2>&& u);

#include <tuple>
#include <utility>
#include <memory>
#include <cassert>

struct B
{
    int id_;

    explicit B(int i = 0) : id_(i) {}

    virtual ~B() {}
};

struct D
    : B
{
    explicit D(int i) : B(i) {}
};


int main()
{
    {
        typedef std::pair<double, std::unique_ptr<D>> T0;
        typedef std::tuple<int, std::unique_ptr<B>> T1;
        T0 t0(2.5, std::unique_ptr<D>(new D(3)));
        T1 t1;
        t1 = std::move(t0);
        assert(std::get<0>(t1) == 2);
        assert(std::get<1>(t1)->id_ == 3);
    }
}
