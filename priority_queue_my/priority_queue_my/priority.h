#pragma once

namespace bit {
    template <class T, class Container = vector<T>, class Compare = less<T> >
    class priority_queue

    {

    public:

        priority_queue() {

        }

        template <class InputIterator>

        priority_queue(InputIterator first, InputIterator last)
            :c(first, last)
        {
            for (int i = (c.size() - 2) / 2; i >= 0; i--)
            {
                adjustDown(i);
            }
        }

        bool empty() const {
            return c.empty();
        }

        size_t size() const {
            return c.size();
        }

        void adjustDown(int parent) {
            int child = parent * 2 + 1;
            
            while (child < c.size())
            {
                if (child + 1 < c.size() && comp(c[child], c[child + 1]))
                {
                    child = child + 1;
                }
                if (comp(c[parent], c[child])) {
                    swap(c[child], c[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        void adjustUp(int child) {
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if (comp(c[parent], c[child])) {
                    swap(c[parent], c[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else {
                    break;
                }
            }
        }

        T& top(){
            return c[0];
        }

        T& top() const {
            return c[0];
        }

        void push(const T& x) {
            c.push_back(x);
            adjustUp(c.size() - 1);
        }

        void pop() {
            swap(c[0], c[c.size() - 1]);
            c.pop_back();
            adjustDown(0);
            
        }

    private:

        Container c;

        Compare comp;

    };

    

    template <class T>
    class Less {
        bool operator()(const T& a1, const T& a2) {
            return a1 < a2;
        }
    };
}
