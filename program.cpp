#include <iostream>
#include <vector>

using namespace std;

struct rect_pos {
    int x;
    int y;
    bool is_vertical;
};

vector<rect_pos> solution(vector<vector<bool>> field, int w_rect, int h_rect) {
    int w = field.size(), h = field[0].size();
    vector<rect_pos> valid_positions;
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            // Vertical check
            bool is_possible = true;
            for (int x_rect = 0; x_rect < w_rect; ++x_rect) {
                for (int y_rect = 0; y_rect < h_rect; ++y_rect) {
                    // Validity of the index check
                    if (x+x_rect >= w || y+y_rect >= h) {
                        is_possible = false;
                        break;
                    }
                    // Checking given cell
                    if (field[x+x_rect][y+y_rect]) {
                        is_possible = false;
                        break;
                    }
                }
                if (!is_possible)
                    break;
            }
            if (is_possible) {
                valid_positions.push_back({x, y, true});
            }
            
            // Horizontal check
            is_possible = true;
            for (int y_rect = 0; y_rect < w_rect; ++y_rect) {
                for (int x_rect = 0; x_rect < h_rect; ++x_rect) {
                    // Validity of the index check
                    if (x+x_rect >= w || y+y_rect >= h) {
                        is_possible = false;
                        break;
                    }
                    if (field[x+x_rect][y+y_rect]) {
                        is_possible = false;
                        break;
                    }
                }
                if (!is_possible)
                    break;
            }
            if (is_possible) {
                valid_positions.push_back({x, y, false});
            }
        }
    }
    return valid_positions;
}

int main() {
    // Write C++ code here
    int w, h;
    cout << "Width and height:" << "\n";
    cin >> w >> h;
    vector<vector<bool>> field(w, vector<bool>(h, false));
    int n_walls;
    cout << "Amount of walls: " << "\n";
    cin >> n_walls;
    for (int i = 0; i < n_walls; ++i) {
        cout << "   Wall " << i+1 << ": \n";
        int x, y;
        cin >> x >> y;
        field[x][y] = true;
    }
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            cout << field[x][y] << " ";   
        }
        cout << "\n";
    }
    cout << "Width and height of rectangle:" << "\n";
    int w_rect, h_rect;
    cin >> w_rect >> h_rect;
    auto answer = solution(field, w_rect, h_rect);
    for (auto i = answer.begin(); i != answer.end(); ++i) {
        cout << i->x << " " << i->y << " " << i->is_vertical << '\n';
    }
    return 0;
}
