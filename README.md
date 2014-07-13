## Traffic-Signs

### 设计目标
----
- 输入：一段含有交通标志的视频，交通标志出现时所在的帧与位置信息
- 输出：该交通标识所出现的所有帧和位置信息、该交通标志在这些帧的截图
- 用途：主要用于为后续使用Deep Learning训练交通标志检测器提供更多的训练样本；也可用于其他视频中物体（如人脸）的追踪。

### 开发环境
----
- 操作系统：Ubuntu Desktop 14.04
- 集成开发环境：Qt Creator 3.0.1 (GCC 4.8.2)
- 依赖库：Qt 4, Boost 1.54, OpenCV 2.4, Eigen 2
- 工程管理：CMake 2.8
- 版本控制：GitHub

### 使用说明
----
1. 复制项目到本地：`git clone https://github.com/Zhejiang-University-GKC/traffic-sign.git`
2. `cd traffic-sign`
3. 可以在外部编译，先新建一个文件夹：`mkdir build`
4. 拷贝配置文件：`cp config/* build/`
5. `cd build`
6. 编译：`cmake .. && make`
7. 运行：`./main`
8. 点击 **Video** 选择视频文件
9. 点击 **Run** 选择需要追踪物体的初始信息并运行

*说明：由于依赖库的安装目录不同，可能需要在编译前修改 cmakelists.txt*


### 队员分工
----
按姓名首字母排序：

- 高涛：GUI, Application frame
- 李逸婷：Imgae processing (feature extraction), classes building
- 毛晨炀：Drawing rectangle, reults saving 
- 徐超颖：Video input, classes building
- 徐可添（组长）：Picture processing, tracking (based on Struck, ICCV 2011), MVVM architecture
