#include "MAP.h"
#include "Point.h"
#include <stdexcept> 



MAP::MAP(int numberX, int numberY, double gridSize)
    : numberX(numberX), numberY(numberY), gridSize(gridSize) {
    grid.resize(numberY, std::vector<int>(numberX, 0)); // Grid'i boyutlandýr ve baþlat
}

void MAP::insertPoint(const Point& point) {
    int indexX = static_cast<int>(point.getX() / this->gridSize);
    int indexY = static_cast<int>(point.getY() / this->gridSize);

    // Harita sýnýrlarýný kontrol et
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        grid[indexY][indexX] = 1; // Noktayý iþaretle
    }
    else {
        throw std::out_of_range("Point is out of map bounds");
    }
}

int MAP::getGrid(int indexX, int indexY) const {
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        return grid[indexY][indexX];
    }
    throw std::out_of_range("Grid index out of bounds");
}

void MAP::setGrid(int indexX, int indexY, int value) {
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        grid[indexY][indexX] = value;
    }
    else {
        throw std::out_of_range("Grid index out of bounds");
    }
}

void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0); // Satýrý sýfýrla
    }
}

void MAP::printInfo() {
    std::cout << "Map Information:" << std::endl;
    std::cout << "NumberX: " << numberX << std::endl;
    std::cout << "NumberY: " << numberY << std::endl;
    std::cout << "GridSize: " << gridSize << std::endl;
}

std::ostream& operator<<(std::ostream& os, const MAP& map) {
    for (int y = 0; y < map.getNumberY(); ++y) {
		for (int x = 0; x < map.getNumberX(); ++x) {
			os << (map.getGrid(x, y) ? 'x' : '.') << ' ';
		}
		os << '\n';
	}
	return os;
}

int MAP::getNumberX() const {
    return numberX;
}

int MAP::getNumberY() const {
    return numberY;
}

double MAP::getGridSize() const {
    return gridSize;
}

void MAP::setGridSize(double _gridsize) {
    if (_gridsize > 0) {
        gridSize = _gridsize;
    }
    else {
        throw std::invalid_argument("Grid size must be positive");
    }
}
