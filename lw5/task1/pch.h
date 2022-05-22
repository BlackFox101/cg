#pragma once

#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <queue>