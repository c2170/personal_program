# personal_program

### /src/

#### head.h

在head.h中定义了两个结构体Line和Point，分别表示由两点(x1,y1)、(x2,y2)所确定的直线Ax+By+C=0和两条直线的交点(x,y)。

#### ConsoleApplication2.cpp

isParallel()函数的功能是判断两条直线是否平行，若平行则返回1，不平行返回0。

在calculate()函数中，首先判断两条直线是否平行，若不平行，则计算出交点坐标，并判断该交点是否与已经存在的交点重合，若不重合，则加入集合中。



### /bin/

### intersect.exe

可执行文件



### /test/

#### UnitTest.cpp

单元测试代码