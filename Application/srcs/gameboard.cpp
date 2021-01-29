#include "gameboard.hpp"
#include <QDebug>
#include <random>

GameBoard::GameBoard( int32_t aDimention,
              QObject *aParent) :
    QAbstractListModel(aParent),
    m_dimention(aDimention),
    m_sizeBoard(m_dimention * m_dimention),
    m_isGameRun(false)
{
    m_gameBoard.resize(m_sizeBoard);
    std::iota(m_gameBoard.begin(), m_gameBoard.end(), 1);
    shuffle();
    // startGame();
}

int GameBoard::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return (m_sizeBoard);
}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    auto const tempIndex = index.row();
    qDebug() << "index: " << m_gameBoard[tempIndex].value;
    return (QVariant::fromValue(m_gameBoard[tempIndex].value));
}

int32_t GameBoard::dimention() const
{
    return m_dimention;
}

bool GameBoard::isGameRun() const
{
    return (m_isGameRun);
}

void GameBoard::move(int aIndex)
{
    auto isSuccess = isValueMove(aIndex);
    qDebug() << "!!: " << isSuccess;
}

void GameBoard::shuffle()
{
    std::random_device rd;
    std::shuffle(m_gameBoard.begin(), m_gameBoard.end(), rd);
}

GameBoard::t_position GameBoard::positionTile(int aIndex)
{
    qint32 col = aIndex / m_dimention;
    qint32 row = aIndex % m_dimention;

    qDebug() << "col: " << col << " row: " << row;
    return {col, row};
}
//  1   2   3   4
//  5   6   7   8
//  9  10  11  12

bool GameBoard::isValueMove(qint32 aIndex)
{
    auto hiddenIter = std::find(m_gameBoard.begin(), m_gameBoard.end(), m_sizeBoard);
    auto hidden = positionTile(std::distance(m_gameBoard.begin(), hiddenIter));

    auto indexIter = std::find(m_gameBoard.begin(), m_gameBoard.end(), aIndex);
    auto index = positionTile(std::distance(m_gameBoard.begin(), indexIter));

    auto temp = positionTile(aIndex);

    qDebug() << "col: " << index.first;
    qDebug() << "row: " << index.second;
    qDebug() << "sampleCol: " << temp.first;
    qDebug() << "sampleRow: " << temp.second;
    qDebug() << "hidCol: " << hidden.first;
    qDebug() << "hidRow: " << hidden.second;

    if (hidden.first == index.first && hidden.second == index.second)
        return (false);

    if ((hidden.first == index.first) && ((hidden.second + 1 == index.second) or
                                   (hidden.second - 1 == index.second)))
        return (true);

    if ((hidden.second == index.second) && ((hidden.first + 1 == index.first) or
                                   (hidden.first - 1 == index.first)))
        return (true);
    return (false);
}

void GameBoard::startGame()
{
    m_gameBoard.resize(m_sizeBoard);
    std::iota(m_gameBoard.begin(), m_gameBoard.end(), 1);
    shuffle();
    m_isGameRun = true;
}
