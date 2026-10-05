# FastNoiseLite

**Inherits:** Noise

Generates noise using the FastNoiseLite library.

This class generates noise using the FastNoiseLite library, which is a collection of several noise algorithms including Cellular, Perlin, Value, and more. Most generated noise values are in the range of `[-1, 1]`, but not always. Some of the cellular noise algorithms return results above `1`.

## Properties

- `cellular_distance_function: FastNoiseLite.CellularDistanceFunction` = `0` — Determines how the distance to the nearest/second-nearest point is computed.
- `cellular_jitter: float` = `1.0` — Maximum distance a point can move off of its grid position.
- `cellular_return_type: FastNoiseLite.CellularReturnType` = `1` — Return type from cellular noise calculations.
- `domain_warp_amplitude: float` = `30.0` — Sets the maximum warp distance from the origin.
- `domain_warp_enabled: bool` = `false` — If enabled, another FastNoiseLite instance is used to warp the space, resulting in a distortion of the noise.
- `domain_warp_fractal_gain: float` = `0.5` — Determines the strength of each subsequent layer of the noise which is used to warp the space.
- `domain_warp_fractal_lacunarity: float` = `6.0` — The change in frequency between octaves, also known as "lacunarity", of the fractal noise which warps the space.
- `domain_warp_fractal_octaves: int` = `5` — The number of noise layers that are sampled to get the final value for the fractal noise which warps the space.
- `domain_warp_fractal_type: FastNoiseLite.DomainWarpFractalType` = `1` — The method for combining octaves into a fractal which is used to warp the space.
- `domain_warp_frequency: float` = `0.05` — Frequency of the noise which warps the space.
- `domain_warp_type: FastNoiseLite.DomainWarpType` = `0` — The warp algorithm.
- `fractal_gain: float` = `0.5` — Determines the strength of each subsequent layer of noise in fractal noise.
- `fractal_lacunarity: float` = `2.0` — Frequency multiplier between subsequent octaves.
- `fractal_octaves: int` = `5` — The number of noise layers that are sampled to get the final value for fractal noise types.
- `fractal_ping_pong_strength: float` = `2.0` — Sets the strength of the fractal ping pong type.
- `fractal_type: FastNoiseLite.FractalType` = `1` — The method for combining octaves into a fractal.
- `fractal_weighted_strength: float` = `0.0` — Higher weighting means higher octaves have less impact if lower octaves have a large impact.
- `frequency: float` = `0.01` — The frequency for all noise types.
- `noise_type: FastNoiseLite.NoiseType` = `1` — The noise algorithm used.
- `offset: Vector3` = `Vector3(0, 0, 0)` — Translate the noise input coordinates by the given Vector3.
- `seed: int` = `0` — The random number seed for all noise types.

## Enum NoiseType

- `TYPE_VALUE = 5` — A lattice of points are assigned random values then interpolated based on neighboring values.
- `TYPE_VALUE_CUBIC = 4` — Similar to value noise (`TYPE_VALUE`), but slower.
- `TYPE_PERLIN = 3` — A lattice of random gradients.
- `TYPE_CELLULAR = 2` — Cellular includes both Worley noise and Voronoi diagrams which creates various regions of the same value.
- `TYPE_SIMPLEX = 0` — As opposed to `TYPE_PERLIN`, gradients exist in a simplex lattice rather than a grid lattice, avoiding directional artifacts.
- `TYPE_SIMPLEX_SMOOTH = 1` — Modified, higher quality version of `TYPE_SIMPLEX`, but slower.

## Enum FractalType

- `FRACTAL_NONE = 0` — No fractal noise.
- `FRACTAL_FBM = 1` — Method using Fractional Brownian Motion to combine octaves into a fractal.
- `FRACTAL_RIDGED = 2` — Method of combining octaves into a fractal resulting in a "ridged" look.
- `FRACTAL_PING_PONG = 3` — Method of combining octaves into a fractal with a ping pong effect.

## Enum CellularDistanceFunction

- `DISTANCE_EUCLIDEAN = 0` — Euclidean distance to the nearest point.
- `DISTANCE_EUCLIDEAN_SQUARED = 1` — Squared Euclidean distance to the nearest point.
- `DISTANCE_MANHATTAN = 2` — Manhattan distance (taxicab metric) to the nearest point.
- `DISTANCE_HYBRID = 3` — Blend of `DISTANCE_EUCLIDEAN` and `DISTANCE_MANHATTAN` to give curved cell boundaries.

## Enum CellularReturnType

- `RETURN_CELL_VALUE = 0` — The cellular distance function will return the same value for all points within a cell.
- `RETURN_DISTANCE = 1` — The cellular distance function will return a value determined by the distance to the nearest point.
- `RETURN_DISTANCE2 = 2` — The cellular distance function returns the distance to the second-nearest point.
- `RETURN_DISTANCE2_ADD = 3` — The distance to the nearest point is added to the distance to the second-nearest point.
- `RETURN_DISTANCE2_SUB = 4` — The distance to the nearest point is subtracted from the distance to the second-nearest point.
- `RETURN_DISTANCE2_MUL = 5` — The distance to the nearest point is multiplied with the distance to the second-nearest point.
- `RETURN_DISTANCE2_DIV = 6` — The distance to the nearest point is divided by the distance to the second-nearest point.

## Enum DomainWarpType

- `DOMAIN_WARP_SIMPLEX = 0` — The domain is warped using the simplex noise algorithm.
- `DOMAIN_WARP_SIMPLEX_REDUCED = 1` — The domain is warped using a simplified version of the simplex noise algorithm.
- `DOMAIN_WARP_BASIC_GRID = 2` — The domain is warped using a simple noise grid (not as smooth as the other methods, but more performant).

## Enum DomainWarpFractalType

- `DOMAIN_WARP_FRACTAL_NONE = 0` — No fractal noise for warping the space.
- `DOMAIN_WARP_FRACTAL_PROGRESSIVE = 1` — Warping the space progressively, octave for octave, resulting in a more "liquified" distortion.
- `DOMAIN_WARP_FRACTAL_INDEPENDENT = 2` — Warping the space independently for each octave, resulting in a more chaotic distortion.
