class ParkingSystem {
private:        
    int bigCars;
    int smallCars;
    int mediumCars;

public:   
    
    ParkingSystem(int big, int medium, int small) {
        bigCars = big;
        smallCars = small;
        mediumCars = medium;
    }
    
    bool addCar(int carType) {
        bool possible = false;
        
        switch (carType) {
            case 1 : 
                if (bigCars - 1 >= 0) {
                    bigCars -= 1;
                    possible = true;
                }
                break;
            case 2 : 
                if (mediumCars - 1 >= 0) {
                    mediumCars -= 1;
                    possible = true;
                }
                break;
            case 3 : 
                if (smallCars - 1 >= 0) {
                    smallCars -= 1;
                    possible = true;
                }
        }
        
        return possible;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */