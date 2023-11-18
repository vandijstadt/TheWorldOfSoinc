#ifndef MOMAP_H
#define MOMAP_H

#include <vector>

using std::vector;

class MOMap
{
public:
    MOMap();
    virtual ~MOMap();
    MOMap(const MOMap& other);
    MOMap& operator=(const MOMap& other);

    vector<vector<char>> Niveau(int niveau);

protected:

private:
};

#endif // MOMAP_H
