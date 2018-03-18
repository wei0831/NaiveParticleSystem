/******************************************************************************/
/*!
\file   CircularObjectPool.h
\author Jack Chang
\date   08/02/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Simple template circular list to mimic object pool for particles.

Diagram for preview of the circular list.
---------------->
|||||||||||||||||    ( Capacity )
|||||||||            ( Count )
Start   End
---------------->
|||||||||||||||||    ( Capacity )
      |||||||||||    ( Count )
      Start     End
---------------->
|||||||||||||||||    ( Capacity )
|||||    ||||||||    ( Count )
    End  Start

When exceed capacity, override the head. (/) - Showing Override
---------------->
|||||||||||||||||    ( Capacity )
||||||||||////|||    ( Count )
              Start
             End
*/
/******************************************************************************/
#ifndef CIRCULAR_OBJ_POOL
#define CIRCULAR_OBJ_POOL

#include <vector>

template <typename T>
class CircularObjectPool
{
    /*--------------------------------------------------------------------------
    // Protected Variables
    --------------------------------------------------------------------------*/
protected:
    std::vector<T>  mList;      // Container
    size_t          mStart;     // Index of 1st item
    size_t          mCount;     // Total number of items

    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    CircularObjectPool(size_t capacity) : mStart(0), mCount(0)
    {
        mList.resize(capacity);
    }

    size_t getCount()
    {
        return mCount;
    }

    size_t getCapacity()
    {
        return mList.size();
    }

    size_t getStart()
    {
        return mStart;
    }

    void setCount(size_t value)
    {
        // If current count is larger than size
        // Warp around and use the oldest item in the list
        if (value > mList.size())
            setStart(mStart + 1);
        else
            mCount = value;
    }

    void setStart(size_t index)
    {
        // Warp around
        mStart = index % mList.size();
    }

    T& operator[](const size_t i)
    {
        return mList[(mStart + i) % mList.size()];
    }

    const T& operator[](const size_t i) const
    {
        return mList[(mStart + i) % mList.size()];
    }

};

#endif
