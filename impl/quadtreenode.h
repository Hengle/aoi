#ifndef __AOI_IMPL_QUADTREENODE_H__
#define __AOI_IMPL_QUADTREENODE_H__

#include "alloc.h"
#include "rect.h"
#include <memory>

namespace aoi
{
    namespace impl
    {
        enum ENodeType
        {
            NodeTypeNormal = 0,  // ��Ҷ�ڵ�
            NodeTypeLeaf = 1,    // Ҷ�ӽڵ�
        };

        const unsigned ChildrenNum = 4;

        template<typename TItem, unsigned NodeCapacity>
        class QuadTreeNode
        {
        public:
            using TNode = QuadTreeNode<TItem, NodeCapacity>;

            QuadTreeNode(MemBase<TNode>* alloc, ENodeType type, QuadTreeNode* parent, const Rect& bounds);
            ~QuadTreeNode();

            bool Insert(TItem* item);
            bool Remove(TItem* item);
            void Query(const Rect& area, TItem*& head, TItem*& tail);
            unsigned GetItemCount();

        public:
#ifdef _DEBUG
            unsigned mLevel;
#endif
            Rect mBounds;                            // �ڵ�߿�Χ
            QuadTreeNode* mParent;                   // ���ڵ�
            ENodeType mNodeType;                     // �ڵ�����
            QuadTreeNode* mChildrens[ChildrenNum];   // ���ӽڵ�
            unsigned mItemCount;                     // Ҷ�ӽڵ��ϵ�Item����
            TItem* mItems;                           // Ҷ�ӽڵ��ϵ�Items

            // TODO: �ھ���Ϣ

        private:
            MemBase<TNode>* mAlloc;                  // �ڵ������
            void split();
            void tryMerge();
        };
    }
}

#include "quadtreenode_impl.h"

#endif
