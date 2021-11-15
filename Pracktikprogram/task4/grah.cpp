#include <iostream>
#include <map>
#include <vector>
#include <exception>

int vertexes;

void adjacencies(std::map<int, std::vector<int>>& v_connect, bool** smeg)
{
	for(unsigned int i = 0; i < v_connect.size(); ++i)
	{
		for(unsigned int j = 0; j < v_connect.size(); ++j)
		{
		    bool flag = false;
			for(unsigned int n = 0; n < v_connect[i].size(); n++){
					
				if(static_cast<int>(j) == v_connect[i][n])
				{
					flag = true;
					break;
				}
			}
				smeg[i][j] = flag;
		}
	}
}

void copy_arr(bool** Narr, bool** Oarr)
{
	for(int i = 0; i < vertexes; ++i)
	{
		for(int j = 0; j < vertexes; ++j)
		{
			Narr[i][j] = Oarr[i][j];
		} 
	}
}

bool** transit(bool** smeg)
{
	bool** transit = new bool*[vertexes];
	for(int count = 0; count < vertexes; ++count) transit[count] = new bool[vertexes];

	copy_arr(transit, smeg);

	for(int i = 0; i < vertexes; ++i)
	{
		for(int j = 0; j < vertexes; ++j)
		{	
			if(i != j && smeg[i][j])
			{
				for(int k = 0; k < vertexes; ++k)
				{
					if(smeg[i][k] == false && smeg[j][k])
					{
						transit[i][k] = true;
					}
				}
			}
		}
	}

	return transit;
} 

void complection(std::map<int, std::vector<int>>& v_connect)
{

	for(int i = 0; i < vertexes; ++i)
	{
		int connection;
		std::cin >> connection;

		if(connection > vertexes) throw std::bad_alloc();

		std::vector<int> vv_con(connection);
		v_connect[i] = vv_con;

		for(int j = 0; j < connection ; ++j)
		{
			int number;
			std::cin >> number;

			v_connect[i][j] = number - 1;
		}
	}
}

void see(bool** mat)
{
	std::cout << '\n';
	for(int i = 0; i < vertexes; ++i)
	{
		for(int j = 0; j < vertexes; ++j)
		{
			std::cout << mat[i][j] << ' '; 
		}
		std::cout << '\n';
	}
}

int main()
{
	std::cin >> vertexes; 
	bool** smeg = new bool*[vertexes];
	for(int count = 0; count < vertexes; ++count) smeg[count] = new bool[vertexes];

	std::map<int, std::vector<int>> v_connect;
	complection(v_connect);

	adjacencies(v_connect, smeg);
	see(smeg);

	bool** transitarr = transit(smeg);
	see(transitarr);

	return 0;
}