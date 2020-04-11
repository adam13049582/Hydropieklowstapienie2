# ifndef MapConfigH
# define MapConfigH
#include <string>
#include <list> 
#include "ConfigModel.h"
#include "FileReader.h"
using namespace std;

class MapConfig : FileReader {
private:
public:
	list<ConfigModel> getConfigForMap();
};
#endif