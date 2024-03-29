#include "headers/matrix.hh"


TwoDimensionalMatrix::TwoDimensionalMatrix() {
    // Constructor
}

TwoDimensionalMatrix::~TwoDimensionalMatrix() {
    // Destructor
}

bool TwoDimensionalMatrix::add_row(int* row, size_t columns) {
    try {
        std::vector<int> vector_row;

        for (int counter = 0; counter < columns; counter++) {
            vector_row.push_back(row[counter]);
        }

        this->matrix.push_back(vector_row);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }
    return false;
}

void TwoDimensionalMatrix::show() {
    printf("[");
    int row_counter = 0;
    for (std::vector<int> row : this->matrix) {
        int counter = 0;
        row_counter++;
        printf("\n  [");
        for (int element : row) {
            counter++;
            printf("%d",element);
            if (counter != row.size()) {
                printf(",");
            }
        }
        printf("]");
        if (row_counter != this->matrix.size()) {
            printf(",");
        } else {
            printf("\n");
        }
    }
    printf("]\n");
}

int TwoDimensionalMatrix::get_rows() {
    int row_counter = 0;

    for (std::vector<int> row : this->matrix) {
        row_counter++;
    }
    
    return row_counter;
}

int TwoDimensionalMatrix::get_columns() {
    int column_counter = 0;
    
    if (this->matrix.size() == 0) {
        return column_counter;
    }

    for (int element : this->matrix[0]) {
        column_counter++;
    }
    
    return column_counter;
}

TwoDimensionalMatrix TwoDimensionalMatrix::calc_sum(TwoDimensionalMatrix matrixB) {
    TwoDimensionalMatrix result_matrix;

    if (this->get_rows() != matrixB.get_rows()) {
        printf("<Sum-Error> Can't add two matrices with different amount of rows!\n");
        return result_matrix;
    }

    if (this->get_columns() != matrixB.get_columns()) {
        printf("<Sum-Error> Can't add two matrices with different amount of columns!\n");
        return result_matrix;
    }
    
    int row_counter = 0;
    for (std::vector<int> Arow : this->matrix) {
        std::vector<int> current_row;
        int column_counter = 0;
        for (int element : Arow) {
            current_row.push_back(Arow[column_counter]+matrixB.matrix[row_counter][column_counter]);
            column_counter++;
        }
        result_matrix.matrix.push_back(current_row);
        row_counter++;
    }

    return result_matrix;
}

TwoDimensionalMatrix TwoDimensionalMatrix::calc_product(TwoDimensionalMatrix matrixB) {
    /*
        Calulate the product of two 2-Dimensional matrices

        „result_matrix = this->matrix * matrixB”
    */
    TwoDimensionalMatrix result_matrix;
    int A_rows = this->get_rows();
    int A_cols = this->get_columns();
    int B_rows = matrixB.get_rows(); // necessary?
    int B_cols = matrixB.get_columns(); // necessary?

    if (A_rows != B_cols) {
        printf("<Multiply-Error> Can't multiply two matrices with an invalid amount of rows and columns!");
        return result_matrix;
    }

    std::vector<int> current_row;

    int col_counter = 0;
    int new_element = 0;
    
    for (std::vector<int> row : this->matrix) { // Iterate rows of this->matrix
        for (int i = 0; i < A_rows; i++) {
            int row_counter = 0;
            for (int element : row) { // Iterate every row-element of this->matrix
                new_element += element * matrixB.matrix[row_counter][col_counter];
                row_counter++;
            }
            col_counter++;
            current_row.push_back(new_element); // Add new element in row for `result_matrix`
            new_element = 0;
        }
        col_counter = 0;
        result_matrix.matrix.push_back(current_row); // Add new row for `result_matrix`
        current_row.clear();
    }

    return result_matrix;
}

void TwoDimensionalMatrix::export_as_static_array(int** static_array) {
    int rows = this->get_rows();
    int columns = this->get_columns();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            static_array[row][col] = this->matrix[row][col];
        }
    }
}

void TwoDimensionalMatrix::import_static_array(int** static_array, int rows, int columns) {
    // ???
}