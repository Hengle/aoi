#ifndef __AOI_IMPL_QUADTREE_H__
#define __AOI_IMPL_QUADTREE_H__

#include "alloc.h"
#include "quadtreenode.h"

namespace aoi
{
    namespace impl
    {

        template<typename TItem, unsigned ItemN, typename TAlloc = Mem<QuadTreeNode<TItem, ItemN>>>
        class QuadTree {
        public:
            using TNode = QuadTreeNode<TItem, ItemN>;

            QuadTree() : mRoot(mAlloc, NodeTypeLeaf) {}
            ~QuadTree() {}

            bool Insert(TItem* item) { return mRoot.Insert(item); }


        private:
            Rect mBounds;        // �ڵ�߿�Χ
            TAlloc mAlloc;       // �ڵ������
            TNode mRoot;         // ���ڵ�
        };
    }
}

#endif
