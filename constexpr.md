#constexpr#

##简介##
> A constant expression is an expression whose value cannot change and that can be evaluated at complile time.A literal is a constant expression.A const object that is initialized from a constant expression is also a constant expression.

const表达式就是值不可改变，并且可以在编译器被求值，因此像字面值或者是被const类型初始化的变量都属于此类型。

`const int max_files = 20; // max_files is a constant expression
const int sz = get_size(); //sz is ont a constant expression`

> In C++ 11, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration.Variables declared as constexpr are implicitly const and must be initialized by constant exprssions

新标准下，我们可以使用constexpr关键字来告诉编译器显式的将一个变量定义为const类型：

`constexpr int mf = 10; 
constexpr int sz = size(); //only if size() is a constexpr function`

//to do: what can used as constexpr
