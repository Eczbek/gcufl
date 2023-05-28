# **XIEITE**
C++ header-only utility library

<br/><br/>

<pre><code>xieite/
|- <a href="./docs/algorithms.md">algorithms</a>/
|  |- <a href="./docs/algorithms/all.md">all</a>
|  |- <a href="./docs/algorithms/any.md">any</a>
|  |- <a href="./docs/algorithms/count.md">count</a>
|  |- <a href="./docs/algorithms/findOccurrence.md">findOccurrence</a>
|  |- <a href="./docs/algorithms/group.md">group</a>
|  |- <a href="./docs/algorithms/isPalindrome.md">isPalindrome</a>
|  |- <a href="./docs/algorithms/numberSearch.md">numberSearch</a>
|  |- <a href="./docs/algorithms/partialReverse.md">partialReverse</a>
|  |- <a href="./docs/algorithms/rotateMatrix.md">rotateMatrix</a>
|  `- <a href="./docs/algorithms/sameRelativeOrder.md">sameRelativeOrder</a>
|- <a href="./docs/concepts.md">concepts</a>/
|  |- <a href="./docs/concepts/Aggregate.md">Aggregate</a>
|  |- <a href="./docs/concepts/Arithmetic.md">Arithmetic</a>
|  |- <a href="./docs/concepts/ConvertibleToOneOf.md">ConvertibleToOneOf</a>
|  |- <a href="./docs/concepts/CopyAssignable.md">CopyAssignable</a>
|  |- <a href="./docs/concepts/Decayed.md">Decayed</a>
|  |- <a href="./docs/concepts/Derivable.md">Derivable</a>
|  |- <a href="./docs/concepts/Enumerator.md">Enumerator</a>
|  |- <a href="./docs/concepts/Functional.md">Functional</a>
|  |- <a href="./docs/concepts/Hashable.md">Hashable</a>
|  |- <a href="./docs/concepts/LinearShape.md">LinearShape</a>
|  |- <a href="./docs/concepts/NoThrowConvertibleTo.md">NoThrowConvertibleTo</a>
|  |- <a href="./docs/concepts/NoThrowConvertibleToOneOf.md">NoThrowConvertibleToOneOf</a>
|  |- <a href="./docs/concepts/Polymorphic.md">Polymorphic</a>
|  |- <a href="./docs/concepts/RangeOf.md">RangeOf</a>
|  |- <a href="./docs/concepts/SameAsOneOf.md">SameAsOneOf</a>
|  |- <a href="./docs/concepts/StreamableInto.md">StreamableInto</a>
|  |- <a href="./docs/concepts/StreamableOutOf.md">StreamableOutOf</a>
|  |- <a href="./docs/concepts/TemporalDuration.md">TemporalDuration</a>
|  |- <a href="./docs/concepts/Trivial.md">Trivial</a>
|  `- <a href="./docs/concepts/UniformRandomBitGenerator.md">UniformRandomBitGenerator</a>
|- <a href="./docs/functions.md">functions</a>/
|  |- <a href="./docs/functions/Infix.md">Infix</a>
|  |- <a href="./docs/functions/OptionalCallOperator.md">OptionalCallOperator</a>
|  |- <a href="./docs/functions/Overloader.md">Overloader</a>
|  |- <a href="./docs/functions/Prefix.md">Prefix</a>
|  `- <a href="./docs/functions/Suffix.md">Suffix</a>
|- <a href="./docs/geometry.md">geometry</a>/
|  |- <a href="./docs/geometry/Line.md">Line</a>
|  |- <a href="./docs/geometry/Point.md">Point</a>
|  |- <a href="./docs/geometry/Polygon.md">Polygon</a>
|  |- <a href="./docs/geometry/Ray.md">Ray</a>
|  |- <a href="./docs/geometry/Segment.md">Segment</a>
|  |- <a href="./docs/geometry/containsPoint.md">containsPoint</a>
|  |- <a href="./docs/geometry/getAngle.md">getAngle</a>
|  |- <a href="./docs/geometry/getArea.md">getArea</a>
|  |- <a href="./docs/geometry/getAxisIntercept.md">getAxisIntercept</a>
|  |- <a href="./docs/geometry/getDistance.md">getDistance</a>
|  |- <a href="./docs/geometry/getIntersections.md">getIntersections</a>
|  |- <a href="./docs/geometry/getLength.md">getLength</a>
|  |- <a href="./docs/geometry/getPerimeter.md">getPerimeter</a>
|  |- <a href="./docs/geometry/getSides.md">getSides</a>
|  |- <a href="./docs/geometry/getSlope.md">getSlope</a>
|  `- <a href="./docs/geometry/rotate.md">rotate</a>
|- <a href="./docs/graphics.md">graphics</a>/
|  `- <a href="./docs/graphics/Color.md">Color</a>
|- <a href="./docs/hashes.md">hashes</a>/
|  |- <a href="./docs/hashes/combine.md">combine</a>
|  |- <a href="./docs/hashes/create.md">create</a>
|  `- <a href="./docs/hashes/distribute.md">distribute</a>
|- <a href="./docs/macros.md">macros</a>/
|  |- <a href="./docs/macros/ARCHITECTURE_TYPE.md">ARCHITECTURE_TYPE</a>
|  |- <a href="./docs/macros/COMPILER_TYPE.md">COMPILER_TYPE</a>
|  |- <a href="./docs/macros/COMPILER_VERSION.md">COMPILER_VERSION</a>
|  |- <a href="./docs/macros/CONCATENATE.md">CONCATENATE</a>
|  |- <a href="./docs/macros/CONSUME.md">CONSUME</a>
|  |- <a href="./docs/macros/DEFER.md">DEFER</a>
|  |- <a href="./docs/macros/EMPTY.md">EMPTY</a>
|  |- <a href="./docs/macros/LOOP.md">LOOP</a>
|  |- <a href="./docs/macros/MATRIX.md">MATRIX</a>
|  |- <a href="./docs/macros/OBSTRUCT.md">OBSTRUCT</a>
|  |- <a href="./docs/macros/REPEAT.md">REPEAT</a>
|  |- <a href="./docs/macros/REPEAT_CONCATENATE.md">REPEAT_CONCATENATE</a>
|  |- <a href="./docs/macros/SCAN.md">SCAN</a>
|  |- <a href="./docs/macros/STANDARD_LANGUAGE.md">STANDARD_LANGUAGE</a>
|  |- <a href="./docs/macros/STANDARD_UNIX.md">STANDARD_UNIX</a>
|  |- <a href="./docs/macros/STRINGIFY.md">STRINGIFY</a>
|  |- <a href="./docs/macros/SYSTEM_TYPE.md">SYSTEM_TYPE</a>
|  |- <a href="./docs/macros/UNIQUE_TOKEN.md">UNIQUE_TOKEN</a>
|  |- <a href="./docs/macros/VANISH.md">VANISH</a>
|  `- <a href="./docs/macros/VERSION.md">VERSION</a>
|- <a href="./docs/math.md">math</a>/
|  |- <a href="./docs/math/BigInteger.md">BigInteger</a>
|  |- <a href="./docs/math/ConditionalIntegerSign.md">ConditionalIntegerSign</a>
|  |- <a href="./docs/math/MinimalIntegerSize.md">MinimalIntegerSize</a>
|  |- <a href="./docs/math/absolute.md">absolute</a>
|  |- <a href="./docs/math/alternatingBits.md">alternatingBits</a>
|  |- <a href="./docs/math/approximatelyEqual.md">approximatelyEqual</a>
|  |- <a href="./docs/math/approximatelyEqualSlope.md">approximatelyEqualSlope</a>
|  |- <a href="./docs/math/closestTo.md">closestTo</a>
|  |- <a href="./docs/math/cosecant.md">cosecant</a>
|  |- <a href="./docs/math/cotangent.md">cotangent</a>
|  |- <a href="./docs/math/difference.md">difference</a>
|  |- <a href="./docs/math/farthestFrom.md">farthestFrom</a>
|  |- <a href="./docs/math/fromBase.md">fromBase</a>
|  |- <a href="./docs/math/isPowerOf2.md">isPowerOf2</a>
|  |- <a href="./docs/math/isPrime.md">isPrime</a>
|  |- <a href="./docs/math/logarithm.md">logarithm</a>
|  |- <a href="./docs/math/minimalBits.md">minimalBits</a>
|  |- <a href="./docs/math/pi.md">pi</a>
|  |- <a href="./docs/math/piDigits.md">piDigits</a>
|  |- <a href="./docs/math/robert.md">robert</a>
|  |- <a href="./docs/math/secant.md">secant</a>
|  |- <a href="./docs/math/tau.md">tau</a>
|  |- <a href="./docs/math/toBase.md">toBase</a>
|  |- <a href="./docs/math/toDegrees.md">toDegrees</a>
|  |- <a href="./docs/math/toRadians.md">toRadians</a>
|  |- <a href="./docs/math/wrap.md">wrap</a>
|  `- <a href="./docs/math/xorShift.md">xorShift</a>
|- <a href="./docs/meta.md">meta</a>/
|  `- <a href="./docs/meta/Version.md">Version</a>
|- <a href="./docs/process.md">process</a>/
|  `- <a href="./docs/process/atExit.md">atExit</a>
|- <a href="./docs/random.md">random</a>/
|  |- <a href="./docs/random/UniformBagDistribution.md">UniformBagDistribution</a>
|  |- <a href="./docs/random/UniformInterruptableDistribution.md">UniformInterruptableDistribution</a>
|  `- <a href="./docs/random/getUUID.md">getUUID</a>
|- <a href="./docs/ratios.md">ratios</a>/
|  |- <a href="./docs/ratios/areas.md">areas</a>
|  |- <a href="./docs/ratios/lengths.md">lengths</a>
|  `- <a href="./docs/ratios/volumes.md">volumes</a>
|- <a href="./docs/strings.md">strings</a>/
|  |- <a href="./docs/strings/repeat.md">repeat</a>
|  |- <a href="./docs/strings/something.md">something</a>
|  |- <a href="./docs/strings/toLowerCase.md">toLowerCase</a>
|  |- <a href="./docs/strings/toUpperCase.md">toUpperCase</a>
|  |- <a href="./docs/strings/trim.md">trim</a>
|  |- <a href="./docs/strings/trimBack.md">trimBack</a>
|  |- <a href="./docs/strings/trimFront.md">trimFront</a>
|  |- <a href="./docs/strings/truncate.md">truncate</a>
|  `- <a href="./docs/strings/whitespaces.md">whitespaces</a>
|- <a href="./docs/system.md">system</a>/
|  |- <a href="./docs/system/detectCosmicRay.md">detectCosmicRay</a>
|  |- <a href="./docs/system/execute.md">execute</a>
|  |- <a href="./docs/system/getAvailableMemory.md">getAvailableMemory</a>
|  |- <a href="./docs/system/getTotalMemory.md">getTotalMemory</a>
|  `- <a href="./docs/system/segmentationFault.md">segmentationFault</a>
|- <a href="./docs/terminal.md">terminal</a>/
|  |- <a href="./docs/terminal/ModeLock.md">ModeLock</a>
|  |- <a href="./docs/terminal/Position.md">Position</a>
|  |- <a href="./docs/terminal/clearLine.md">clearLine</a>
|  |- <a href="./docs/terminal/clearScreen.md">clearScreen</a>
|  |- <a href="./docs/terminal/getCharacter.md">getCharacter</a>
|  |- <a href="./docs/terminal/getCursorPosition.md">getCursorPosition</a>
|  |- <a href="./docs/terminal/getString.md">getString</a>
|  |- <a href="./docs/terminal/getWindowSize.md">getWindowSize</a>
|  |- <a href="./docs/terminal/putBackString.md">putBackString</a>
|  |- <a href="./docs/terminal/resetStyle.md">resetStyle</a>
|  |- <a href="./docs/terminal/setColorBackground.md">setColorBackground</a>
|  |- <a href="./docs/terminal/setColorDim.md">setColorDim</a>
|  |- <a href="./docs/terminal/setColorForeground.md">setColorForeground</a>
|  |- <a href="./docs/terminal/setColorInversion.md">setColorInversion</a>
|  |- <a href="./docs/terminal/setCursorAlternative.md">setCursorAlternative</a>
|  |- <a href="./docs/terminal/setCursorPosition.md">setCursorPosition</a>
|  |- <a href="./docs/terminal/setCursorVisibility.md">setCursorVisibility</a>
|  |- <a href="./docs/terminal/setScreenAlternative.md">setScreenAternative</a>
|  |- <a href="./docs/terminal/setTextBlink.md">setTextBlink</a>
|  |- <a href="./docs/terminal/setTextBold.md">setTextBold</a>
|  |- <a href="./docs/terminal/setTextItalic.md">setTextItalic</a>
|  |- <a href="./docs/terminal/setTextStrikethrough.md">setTextStrikethrough</a>
|  |- <a href="./docs/terminal/setTextUnderline.md">setTextUnderline</a>
|  `- <a href="./docs/terminal/setTextVisibility.md">setTextVisibility</a>
|- <a href="./docs/threads.md">threads</a>/
|  |- <a href="./docs/threads/Interval.md">Interval</a>
|  |- <a href="./docs/threads/Loop.md">Loop</a>
|  `- <a href="./docs/threads/Timeout.md">Timeout</a>
|- <a href="./docs/traits.md">traits</a>/
|  |- <a href="./docs/traits/isFunctional.md">isFunctional</a>
|  `- <a href="./docs/traits/isTemporalDuration.md">isTemporalDuration</a>
`- <a href="./docs/types.md">types</a>/
   |- <a href="./docs/types/Anything.md">Anything</a>
   |- <a href="./docs/types/List.md">List</a>
   |- <a href="./docs/types/Unique.md">Unique</a>
   |- <a href="./docs/types/count.md">count</a>
   `- <a href="./docs/types/demangle.md">demangle</a>
</code></pre>
