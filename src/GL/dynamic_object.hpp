#pragma once

#include <unordered_set>

namespace GL
{

    class DynamicObject
    {
    public:
        virtual ~DynamicObject() {}

        // TASK-0 - C.4)
        virtual bool move() = 0;
    };

    inline std::unordered_set<DynamicObject *> move_queue;

} // namespace GL
