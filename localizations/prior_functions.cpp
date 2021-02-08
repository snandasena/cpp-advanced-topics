#include<iostream>
#include<vector>

using namespace std;

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev);

int main()
{
    float position_stdev = 1.0f;
    int map_size = 25;
    vector<float> landmark_positions{5, 10, 20};

    vector<float> priors = initialize_priors(map_size, landmark_positions, position_stdev);

    for (int i = 0; i < priors.size(); ++i)
    {
        cout << priors[i] << "\n";
    }

}

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev)
{
    vector<float> priors(map_size, 0.0);
    float norm_term = landmark_positions.size() * (position_stdev * 2 + 1);
    for (int i = 0; i < landmark_positions.size(); ++i)
    {
        for (float j = 1; j <= position_stdev; ++j)
        {
            priors.at(int(j + landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
            priors.at(int(-j + landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
        }
        priors.at(landmark_positions[i]) + 1.0 / norm_term;
    }

    return priors;
}

