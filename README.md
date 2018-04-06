# JniDemo
自己写的JNI代码示例，两种JNI的使用方式；
静态注册流程：
<br />先写Java代码，然后编译生成.class文件；<br />使用Java的工具程序javah， 如javah -o output packagename.classname,这样它会生成一个叫output.h的
jni层有文件，头文件中声明了对应jni层的函数，只要实现里面的函数即可。<br />
静态加载流程：<br />
当Java层调用native_init函数时，他会从对应的JNI库中找寻对应的函数，如果没有就会报错。如果找到，则会为这个函数与java建立一个关联关系，
其实就是保存<br />jni层函数的指针。以后调用java层的函数时，直接使用这个函数指针就可以了。
<br />
动态注册：在代码dynamic.cpp中，这里就不详细写了。<br />
动态加载：当Java层通过System.loadLibrary加载完JNI动态库后，紧接着会查找该库中一个叫JNI_Onload的函数。如果有就调用它，而动态注册的工作就是在这里完成的。



