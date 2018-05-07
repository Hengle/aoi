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

        template<typename TItem, unsigned ItemN>
        class QuadTreeNode
        {
        public:
            using TNode = QuadTreeNode<TItem, ItemN>;

            QuadTreeNode(MemBase<TNode>* alloc, ENodeType type, QuadTreeNode* parent = nullptr);
            ~QuadTreeNode();

            void Reset();
            bool Insert(TItem* item);

        public:
            Rect mBounds;                      // �ڵ�߿�Χ
            QuadTreeNode* mParent;             // ���ڵ�
            ENodeType mNodeType;               // �ڵ�����
            union
            {
                QuadTreeNode* mChildrens[4];   // ���ӽڵ�
                struct
                {
                    unsigned mItemCount;       // Ҷ�ӽڵ��ϵ�Item����
                    TItem* mItems[ItemN];      // Ҷ�ӽڵ��ϵ�Items
                };
            };

            // TODO: �ھ���Ϣ

        private:
            MemBase<TNode>* mAlloc;                // �ڵ������
            void createChildrens();
        };
    }
}

#include "quadtreenode_impl.h"

#endif
