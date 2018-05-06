#ifndef __AOI_IMPL_QUADTREENODE_H__
#define __AOI_IMPL_QUADTREENODE_H__

#include "rect.h"
#include <memory>

namespace aoi
{
    namespace impl
    {
        enum NodeType
        {
            NodeTypeNormal = 0,  // ��Ҷ�ڵ�
            NodeTypeLeaf = 1,    // Ҷ�ӽڵ�
        };

        template<typename TItem, unsigned ItemN>
        class QuadTreeNode
        {
        public:
            QuadTreeNode();
            ~QuadTreeNode();

            void Reset();
            bool Insert(TItem* item);

        public:
            Rect mBounds;                      // �ڵ�߿�Χ
            QuadTreeNode* mParent;             // ���ڵ�
            NodeType mNodeType;                // �ڵ�����
            union
            {
                QuadTreeNode* mChildrens[4];   // ���ӽڵ�
                struct
                {
                    unsigned mItemCount;       // Ҷ�ӽڵ��ϵ�Item����
                    TItem* mItems[ItemN];      // Ҷ�ӽڵ��ϵ�Items
                };
            }mContent;
            
            // TODO: �ھ���Ϣ
        };
    }
}

#include "quadtreenode_impl.h"

#endif
