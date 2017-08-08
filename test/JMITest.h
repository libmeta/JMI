#include "jmi.h"

struct JMITestClassTag : jmi::ClassTag { static std::string name() { return "JMITest";} };
class JMITestCached : public jmi::JObject<JMITestClassTag> // can not use CRTP
{
public:
    void setX(int v);
    int getX() const;
    static void setY(int v);
    static int getY();
    void setStr(const char* v);
    std::string getStr() const;
    // java array is of fixed size
    static void getSStr(std::array<std::string,1>& v);
    void getIntArray(int v[2]) const;
    void getIntArray(std::array<int, 2>& v) const;
    JMITestCached getSelf() const;
};

class JMITestUncached : public jmi::JObject<JMITestClassTag>
{
public:
    void setX(int v);
    int getX() const;
    static void setY(int v);
    static int getY();
    void setStr(const std::string& v);
    std::string getStr() const;

    void getIntArray(int v[2]) const;
    void getIntArray(std::array<int, 2>& v) const;
};