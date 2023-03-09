#pragma once
#include <xieite/algorithms/all.hpp>
#include <xieite/algorithms/any.hpp>
#include <xieite/algorithms/count.hpp>
#include <xieite/algorithms/findOccurence.hpp>
#include <xieite/algorithms/isPalindrome.hpp>
#include <xieite/algorithms/partialReverse.hpp>
#include <xieite/algorithms/rotatedMatch.hpp>
#include <xieite/concepts/Aggregate.hpp>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/concepts/Comparator.hpp>
#include <xieite/concepts/Decayed.hpp>
#include <xieite/concepts/Enumerator.hpp>
#include <xieite/concepts/StreamableIn.hpp>
#include <xieite/concepts/StreamableOut.hpp>
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/concepts/Trivial.hpp>
#include <xieite/concepts/UniformRandomBitGenerator.hpp>
#include <xieite/console/CursorPosition.hpp>
#include <xieite/console/NonBlockLock.hpp>
#include <xieite/console/RawLock.hpp>
#include <xieite/console/codes.hpp>
#include <xieite/console/cursorControls.hpp>
#include <xieite/console/getCursorPosition.hpp>
#include <xieite/console/getKeyPress.hpp>
#include <xieite/console/getWindowSize.hpp>
#include <xieite/console/moveCursor.hpp>
#include <xieite/console/readBuffer.hpp>
#include <xieite/console/setBackground.hpp>
#include <xieite/console/setCursorPosition.hpp>
#include <xieite/console/setForeground.hpp>
#include <xieite/containers/OrderedMap.hpp>
#include <xieite/errors/segmentationFault.hpp>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/containsPoint.hpp>
#include <xieite/geometry/getAngle.hpp>
#include <xieite/geometry/getArea.hpp>
#include <xieite/geometry/getBoundingBox.hpp>
#include <xieite/geometry/getCircumference.hpp>
#include <xieite/geometry/getDistance.hpp>
#include <xieite/geometry/getInterceptX.hpp>
#include <xieite/geometry/getInterceptY.hpp>
#include <xieite/geometry/getIntersection.hpp>
#include <xieite/geometry/getIntersections.hpp>
#include <xieite/geometry/getLength.hpp>
#include <xieite/geometry/getPerimeter.hpp>
#include <xieite/geometry/getSides.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/graphics/Color.hpp>
#include <xieite/macros/ARCHITECTURE_TYPE.hpp>
#include <xieite/macros/ASSERT.hpp>
#include <xieite/macros/COMPILER_TYPE.hpp>
#include <xieite/macros/COMPILER_VERSION.hpp>
#include <xieite/macros/CONCATENATE.hpp>
#include <xieite/macros/MATRIX.hpp>
#include <xieite/macros/PLATFORM_TYPE.hpp>
#include <xieite/macros/QUOTE.hpp>
#include <xieite/macros/REPEAT.hpp>
#include <xieite/math/BigInteger.hpp>
#include <xieite/math/absolute.hpp>
#include <xieite/math/approximatelyEqual.hpp>
#include <xieite/math/closestTo.hpp>
#include <xieite/math/cosecant.hpp>
#include <xieite/math/cotangent.hpp>
#include <xieite/math/difference.hpp>
#include <xieite/math/farthestFrom.hpp>
#include <xieite/math/fromBase.hpp>
#include <xieite/math/isNaN.hpp>
#include <xieite/math/isPrime.hpp>
#include <xieite/math/pi.hpp>
#include <xieite/math/piDigits.hpp>
#include <xieite/math/secant.hpp>
#include <xieite/math/squareRoot.hpp>
#include <xieite/math/tau.hpp>
#include <xieite/math/toBase.hpp>
#include <xieite/math/toDegrees.hpp>
#include <xieite/math/toRadians.hpp>
#include <xieite/math/wrap.hpp>
#include <xieite/process/atExit.hpp>
#include <xieite/random/InterruptableUniformDistribution.hpp>
#include <xieite/random/getUUID.hpp>
#include <xieite/string/hash.hpp>
#include <xieite/string/repeat.hpp>
#include <xieite/string/split.hpp>
#include <xieite/string/toLowercase.hpp>
#include <xieite/string/toUppercase.hpp>
#include <xieite/string/trimEnd.hpp>
#include <xieite/string/trimStart.hpp>
#include <xieite/string/truncate.hpp>
#include <xieite/system/execute.hpp>
#include <xieite/threads/Interval.hpp>
#include <xieite/threads/Loop.hpp>
#include <xieite/threads/Timeout.hpp>
#include <xieite/traits/isTemporalDuration.hpp>
#include <xieite/types/demangle.hpp>
#include <xieite/units/lengths.hpp>
#include <xieite/vector/group.hpp>
#include <xieite/vector/rotateMatrix.hpp>
#include <xieite/vector/uniques.hpp>
