#include <QtTest>
#include <QCoreApplication>
#include "gameboard.hpp"

// add necessary includes here

class TestGameBorder : public QObject
{
    Q_OBJECT

public:
    TestGameBorder();
    ~TestGameBorder();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void gameBoard_data();
    void gameBoard();
    void toUpper_data();
    void toUpper();

};

TestGameBorder::TestGameBorder()
{

}

TestGameBorder::~TestGameBorder()
{

}

void TestGameBorder::initTestCase()
{

}

void TestGameBorder::cleanupTestCase()
{

}

void TestGameBorder::test_case1()
{
}

void TestGameBorder::gameBoard_data()
{
}

void TestGameBorder::gameBoard()
{
    GameBoard game;

    QCOMPARE(game.dimention(), 4);
    QCOMPARE(game.rowCount({}), 16);
}

/* *************************************** */

void TestGameBorder::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed") << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestGameBorder::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

QTEST_MAIN(TestGameBorder)

#include "tst_testgameborder.moc"
