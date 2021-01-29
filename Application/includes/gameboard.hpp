#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <QAbstractListModel>
#include <algorithm>

// signal change isgamerun
// signal change startgame

struct Tile {
    int32_t  value;

    Tile(int32_t aValue = 0) :
        value(aValue)
    {
    }

    Tile &operator =(int32_t aValue)
    {
        value = aValue;
        return (*this);
    }

    bool operator ==(int32_t aValue)
    {
        return (value == aValue);
    }

    operator QString() const
    {
        return QString::number(value);
    };
};

// ------------------------------------------------



class GameBoard :
        public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimention READ dimention CONSTANT)
    // Q_PROPERTY(bool isGameRun READ isGameRun CONSTANT)

    typedef std::pair<int, int> t_position;
public:
    static const int32_t defaultDemention {4};
    GameBoard(int32_t aDimention = defaultDemention,
              QObject *aParent = nullptr);

    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    int32_t dimention() const;
    bool isGameRun() const;
    Q_INVOKABLE void move(int aIndex);
    Q_INVOKABLE void startGame();

private:

    std::vector<Tile> m_gameBoard;
    int32_t           m_dimention;
    int32_t           m_sizeBoard;
    bool              m_isGameRun;

    // GameBoard private Methods
    void shuffle();
    t_position positionTile(int aIndex);
    bool isValueMove(qint32 aIndex);
};

#endif // GAMEBOARD_HPP
