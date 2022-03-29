#pragma once

#include <vector>
#include <algorithm>

namespace GL
{

    // a displayable object can be displayed and has a z-coordinate indicating who
    // is displayed before whom ;]

    class Displayable
    {
    protected:
        float z = 0;

    public:
        Displayable(const float z_) : z{z_}
        {
            // TASK_0 - C.5)
            display_queue.emplace_back(this);
        }
        virtual ~Displayable()
        {
            // TASK_0 - C.5)
            display_queue.erase(
                std::find(display_queue.begin(),
                          display_queue.end(),
                          this));
        }

        virtual void display() const = 0;

        float get_z() const { return z; }

        // TASK_0 - C.5)
        static inline std::vector<const Displayable *> display_queue;
    };

    struct disp_z_cmp
    {
        bool operator()(const Displayable *a, const Displayable *b) const
        {
            const auto az = a->get_z();
            const auto bz = b->get_z();
            return (az == bz) ? (a > b) : (az > bz);
        }
    };
} // namespace GL
