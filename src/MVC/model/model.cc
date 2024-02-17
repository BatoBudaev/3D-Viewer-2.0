#include "model.h"

namespace s21 {

Model::Model() {
  object_ = s21::Surface();
  error_code_ = OK;
}

int Model::error_code() { return error_code_; }

void Model::reset_data() {
  error_code_ = OK;
  object_ = s21::Surface();
};

void Model::parser(std::string filename) {
  reset_data();
  std::ifstream stream(filename);
  if (stream.fail() ||
      filename.substr(filename.find_last_of(".") + 1) != "obj") {
    error_code_ = ERROR;
    object_.count_vertex = 0;
    object_.count_polygons = 0;
    object_.array_vertex = {};
    object_.array_polygon = {};
  } else {
    parse_count(filename);
    if (error_code_ == OK) {
      double x, y, z;
      std::ifstream stream(filename);
      for (std::string line; getline(stream, line) && error_code_ == OK;) {
        if (line[0] == 'v' && line[1] == ' ') {
          std::istringstream iss(line.substr(2));
          if (!(iss >> x >> y >> z)) {
            error_code_ = ERROR;
          } else {
            object_.array_vertex.push_back(x);
            object_.array_vertex.push_back(y);
            object_.array_vertex.push_back(z);
          }
        }
        if (line[0] == 'f' && line[1] == ' ') {
          parse_f(line);
        }
      }
    } else {
      error_code_ = ERROR;
    }
  }
}

void Model::parse_count(std::string filename) {
  object_.count_vertex = 0;
  object_.count_polygons = 0;
  size_t f_count;
  std::ifstream input(filename);
  for (std::string line; getline(input, line) && error_code_ == OK;) {
    if (line[0] == 'v' && line[1] == ' ') {
      object_.count_vertex += 3;
    }
    if (line[0] == 'f' && line[1] == ' ') {
      f_count = parse_f_count(line);
      if (f_count >= 3)
        object_.count_polygons += f_count;
      else
        error_code_ = ERROR;
    }
  }
  if (object_.count_vertex == 0 || object_.count_polygons == 0 ||
      error_code_ == ERROR) {
    error_code_ = ERROR;
    object_.count_vertex = 0;
    object_.count_polygons = 0;
  }
}

size_t Model::parse_f_count(std::string line) {
  char *f_line = strdup(line.c_str() + 2);
  int tmp;
  size_t f_count = 0;
  char *token = strtok(f_line, " ");
  while (token != NULL && strcmp(token, "\r") != 0) {
    std::istringstream tokenStream(token);

    if (tokenStream >> tmp) {
      f_count++;
    } else {
      error_code_ = ERROR;
    }

    token = strtok(NULL, " ");
  }
  free(f_line);
  return f_count;
}

void Model::parse_f(std::string line) {
  char *f_line = strdup(line.c_str() + 2);
  int current = 0, tmp = 0;
  char *token = strtok(f_line, " ");

  std::istringstream tokenStream(token);
  if (tokenStream >> current) {
    object_.array_polygon.push_back(current - 1);
    tmp = current;
  }

  token = strtok(NULL, " ");
  while (token != NULL && strcmp(token, "\r") != 0) {
    std::istringstream tokenStream(token);
    if (tokenStream >> current) {
      object_.array_polygon.push_back(current - 1);
      object_.array_polygon.push_back(current - 1);
    } else
      error_code_ = ERROR;
    token = strtok(NULL, " ");
  }
  object_.array_polygon.push_back(tmp - 1);
  free(f_line);
}

void Model::move(Vertex offset) {
  if (object_.array_vertex.empty() || object_.count_vertex <= 0 ||
      object_.array_vertex.size() % 3 != 0) {
    error_code_ = ERROR;
  } else {
    for (size_t i = 0; i < object_.array_vertex.size(); i += 3) {
      object_.array_vertex[i] += offset.x_;
      object_.array_vertex[i + 1] += offset.y_;
      object_.array_vertex[i + 2] += offset.z_;
    }
  }
}

void Model::rotateX(double angle) {
  double k = 180.0 / M_PI;
  angle /= k;
  int len = object_.array_vertex.size();
  if (len % 3 != 0 || object_.array_vertex.empty()) {
    error_code_ = ERROR;
  } else {
    for (int i = 0; i < len; i += 3) {
      double y = object_.array_vertex.at(i + 1) * cos(angle) -
                 object_.array_vertex.at(i + 2) * sin(angle);
      double z = object_.array_vertex.at(i + 1) * sin(angle) +
                 object_.array_vertex.at(i + 2) * cos(angle);
      object_.array_vertex.at(i + 1) = y;
      object_.array_vertex.at(i + 2) = z;
    }
  }
}

void Model::rotateY(double angle) {
  double k = 180.0 / M_PI;
  angle /= k;
  int len = object_.array_vertex.size();
  if (len % 3 != 0 || object_.array_vertex.empty()) {
    error_code_ = ERROR;
  } else {
    for (int i = 0; i < len; i += 3) {
      double x = object_.array_vertex.at(i + 2) * sin(angle) +
                 object_.array_vertex.at(i) * cos(angle);
      double z = object_.array_vertex.at(i + 2) * cos(angle) -
                 object_.array_vertex.at(i) * sin(angle);
      object_.array_vertex.at(i) = x;
      object_.array_vertex.at(i + 2) = z;
    }
  }
}

void Model::rotateZ(double angle) {
  double k = 180.0 / M_PI;
  angle /= k;
  int len = object_.array_vertex.size();
  if (len % 3 != 0 || object_.array_vertex.empty()) {
    error_code_ = ERROR;
  } else {
    for (int i = 0; i < len; i += 3) {
      double x = object_.array_vertex.at(i) * cos(angle) -
                 object_.array_vertex.at(i + 1) * sin(angle);
      double y = object_.array_vertex.at(i) * sin(angle) +
                 object_.array_vertex.at(i + 1) * cos(angle);
      object_.array_vertex.at(i) = x;
      object_.array_vertex.at(i + 1) = y;
    }
  }
}

void Model::scale(double value) {
  int len = object_.array_vertex.size();
  if (len % 3 != 0 || object_.array_vertex.empty()) {
    error_code_ = ERROR;
  } else {
    for (int i = 0; i < len; i += 3) {
      object_.array_vertex[i] *= value;
      object_.array_vertex[i + 1] *= value;
      object_.array_vertex[i + 2] *= value;
    }
  }
}

void min_max(double *min, double *max, double value) {
  if (value < *min) *min = value;
  if (value > *max) *max = value;
}

void Model::start_frame() {
  int len = object_.array_vertex.size();
  if (len % 3 != 0 || object_.array_vertex.empty()) {
    error_code_ = ERROR;
  } else {
    double x_min = object_.array_vertex[0], x_max = object_.array_vertex[0];
    double y_min = object_.array_vertex[1], y_max = object_.array_vertex[1];
    double z_min = object_.array_vertex[2], z_max = object_.array_vertex[2];
    for (int i = 3; i < len; i += 3) {
      min_max(&x_min, &x_max, object_.array_vertex[i]);
      min_max(&y_min, &y_max, object_.array_vertex[i + 1]);
      min_max(&z_min, &z_max, object_.array_vertex[i + 2]);
    }

    Vertex center(0, 0, 0, 1);
    center.x_ -= x_min + (x_max - x_min) / 2;
    center.y_ -= y_min + (y_max - y_min) / 2;
    center.z_ -= z_min + (z_max - z_min) / 2;
    Model::move(center);

    double max = x_max;
    if (max < y_max) max = y_max;
    if (max < z_max) max = z_max;
    double value = 1;
    double scal = (value - (value * -1)) / max;
    Model::scale(scal);
  }
}
}  // namespace s21
