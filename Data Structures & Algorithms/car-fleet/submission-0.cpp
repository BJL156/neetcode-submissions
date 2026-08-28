class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, double>> cars;
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({ position[i], time });
        }

        sort(cars.rbegin(), cars.rend());

        std::stack<double> monoSt;
        for (auto &[position, time] : cars) {
            if (monoSt.empty() || time > monoSt.top()) {
                monoSt.push(time);
            }
        }

        return monoSt.size();
    }
};
