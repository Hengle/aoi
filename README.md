# aoi

相关文档：<wiki/AOI介绍.md>

## 已完成

- 实现传统四叉树功能
- 树节点内存分配优化

## 目前性能参考

![图1](assets/1.jpg)

相关内容  | 说明
----- | -----------------------------------
测试例子  | [tests/test2](tests/test2/main.cpp)
场景大小  | 8000 * 8000
游戏对象数 | 5000
AOI半径 | 50

**测试机器配置**

阿里云ECS服务器，配置： 1 vCPU 2 GB (I/O优化) ecs.t5-lc1m2.small 1Mbps

**后续实现四叉树的邻居关系后再做基准比较**

## TODO

- 实现四叉树的邻居关系
- 提供层数限制，避免外部错误数据，导致树无限分裂
- 提供AOI接口
