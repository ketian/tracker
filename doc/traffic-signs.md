## Traffic-Signs

### 设计目标
----
- 输入：一段含有交通标志的视频，交通标志出现时所在的帧与位置信息
- 输出：该交通标识所出现的所有帧和位置信息、该交通标志在这些帧的截图
- 用途：主要用于为后续使用Deep Learning训练交通标志检测器提供更多的训练样本

### 开发环境
----
- 操作系统：Ubuntu Desktop 14.04
- 集成开发环境：Qt Creator
- 依赖库：Qt, Boost, OpenCV 2.4
- 工程管理：CMake
- 版本控制：GitHub

### 队员分工
----
按姓名首字母排序：

- 高涛：GUI, Application frame
- 李逸婷：Picture processing (feature extraction)
- 毛晨炀：Drawing, reults saving 
- 徐超颖：Video input
- 徐可添（组长）：Picture processing, tracking (based on Struck, ICCV 2011)