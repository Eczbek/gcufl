#ifndef XIEITE_HEADER__ALGORITHMS__ROTATE_MATRIX
#	define XIEITE_HEADER__ALGORITHMS__ROTATE_MATRIX

#	include <concepts>
#	include <vector>
#	include "../math/wrap.hpp"

namespace xieite::algorithms {
	template<std::copyable Value>
	constexpr std::vector<std::vector<Value>> rotateMatrix(const std::vector<std::vector<Value>>& matrix, int rotations) noexcept {
		rotations = xieite::math::wrap(rotations, 2, -1);
		if (!rotations) {
			return matrix;
		}
		const std::size_t matrixWidth = matrix.size();
		const std::size_t matrixHeight = matrix[0].size();
		auto result = std::vector<std::vector<Value>>(matrixHeight);
		if (rotations > 0) {
			for (std::size_t x = matrixWidth; x--;) {
				for (std::size_t y = 0; y < matrixHeight; ++y) {
					result[y].push_back(matrix[x][y]);
				}
			}
			return xieite::algorithms::rotateMatrix(result, rotations - 1);
		}
		for (std::size_t x = 0; x < matrixWidth; ++x) {
			for (std::size_t y = matrixHeight; y--;) {
				result[y].push_back(matrix[x][y]);
			}
		}
		return result;
	}
}

#endif
