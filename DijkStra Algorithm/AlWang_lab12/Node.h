#ifndef NODE_h
#define NODE_h

class Node
{
public:
    Node();
    ~Node();

    int getVertexNum() const;
    int getDistFromTree() const;
    int getNearestInsider() const;

    void setVertexNum(int num);
    void setDistFromTree(int dist);
    void setNearestInsider(int insider);

private:
    int m_number = 0;
    int m_dist = 0;
    int m_nearestInsider = 0;
};

#endif
