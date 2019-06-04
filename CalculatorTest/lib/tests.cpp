#include "Calculator/Calculator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace {
    class ClassTest : public testing::Test {
    public:
        Calculator calculator_;
        Context context_;
    protected:
        void SetUp() {
            calculator_ = Calculator();
            context_ = Context();
        }
    };
}

TEST_F(ClassTest, testPushPopPlus)
{
    Command commandPush = {"PUSH", "25"};
    Command commandPlus = {"+"};
    Command commandPop = {"POP"};

    calculator_.exec(commandPush);
    calculator_.exec(commandPush);
    calculator_.exec(commandPlus);
    calculator_.exec(commandPush);
    calculator_.exec(commandPop);

    context_ = calculator_.getContext();
    ASSERT_EQ(context_.top(),50);
}


TEST_F(ClassTest, testMulDivPlusMinus)
{
    Command commandPush = {"PUSH", "10"};
    Command commandPush1 = {"PUSH", "4000"};
    Command commandPush2 = {"PUSH", "30"};

    Command commandPlus = {"+"};
    Command commandMul = {"*"};
    Command commandDiv = {"/"};
    Command commandMinus = {"-"};

    calculator_.exec(commandPush);
    calculator_.exec(commandPush);
    calculator_.exec(commandPlus); //10+10
    calculator_.exec(commandPush);
    calculator_.exec(commandMul); //20*10
    calculator_.exec(commandPush1);
    calculator_.exec(commandDiv); //4000/200
    calculator_.exec(commandPush2);
    calculator_.exec(commandMinus); //30-20

    context_ = calculator_.getContext();
    ASSERT_EQ(context_.top(),10);
}

TEST_F(ClassTest, testDefine)
{
    Command commandPush = {"PUSH", "a"};
    Command commandDefine = {"DEFINE", "a","30"};

    calculator_.exec(commandDefine);
    calculator_.exec(commandPush);

    context_ = calculator_.getContext();
    ASSERT_EQ(context_.top(),30);
}

TEST_F(ClassTest, testRedefine)
{
    Command commandPush = {"PUSH", "a"};
    Command commandDefine1 = {"DEFINE", "a","30"};
    Command commandDefine2 = {"DEFINE", "a","40"};

    calculator_.exec(commandDefine1);
    calculator_.exec(commandDefine2);
    calculator_.exec(commandPush);

    context_ = calculator_.getContext();
    ASSERT_EQ(context_.top(),40);
}

TEST_F(ClassTest, testIncorrectDefine)
{
    Command commandPush = {"PUSH", "a"};
    Command commandDefine = {"DEFINE", "a","30asdas"};

    ASSERT_THROW(calculator_.exec(commandDefine),InvalidInput);
    //calculator_.exec(commandPush);

}

TEST_F(ClassTest, testDivisionByZero)
{
    Command commandPush1 = {"PUSH", "0"};
    Command commandPush2 = {"PUSH", "10"};
    Command commandDiv = {"/"};

    calculator_.exec(commandPush1);
    calculator_.exec(commandPush2);
    ASSERT_THROW(calculator_.exec(commandDiv), ZeroDivision);
}


TEST_F(ClassTest, testIncorrectInput)
{
    Command commandErr = {"ERROR"};

    ASSERT_THROW(calculator_.exec(commandErr), std::out_of_range);
}

TEST_F(ClassTest, testPrint)
{
    Command commandPush1 = {"PUSH", "10"};
    Command commandPrint = {"PRINT"};

    calculator_.exec(commandPush1);
    calculator_.exec(commandPrint);
}

TEST_F(ClassTest, testEquation)
{
    Command commandPushA = {"PUSH", "3"};
    Command commandPushB = {"PUSH", "-14"};
    Command commandPushC = {"PUSH", "-5"};
    Command commandPush4 = {"PUSH", "4"};
    Command commandPush2 = {"PUSH", "2"};
    Command commandPush1 = {"PUSH", "1"};
    Command commandPushNot1 = {"PUSH", "-1"};

    Command commandPlus = {"+"};
    Command commandMul = {"*"};
    Command commandDiv = {"/"};
    Command commandMinus = {"-"};
    Command commandSqrt = {"SQRT"};

    calculator_.exec(commandPush2);
    calculator_.exec(commandPushA);
    calculator_.exec(commandMul);


    calculator_.exec(commandPushC);
    calculator_.exec(commandPushA);
    calculator_.exec(commandPush4);
    calculator_.exec(commandPushNot1);

    calculator_.exec(commandMul);
    calculator_.exec(commandMul);
    calculator_.exec(commandMul);

    calculator_.exec(commandPushB);
    calculator_.exec(commandPushB);
    calculator_.exec(commandMul);

    calculator_.exec(commandPlus);

    calculator_.exec(commandSqrt);

    calculator_.exec(commandPushB);
    calculator_.exec(commandPushNot1);
    calculator_.exec(commandMul);

    calculator_.exec(commandPlus);

    calculator_.exec(commandDiv);
    
    context_ = calculator_.getContext();
    ASSERT_EQ(context_.top(),5);
}
