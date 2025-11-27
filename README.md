# ASCII Turn-Based Renderer (Engine)

A small terminal rendering engine built around **glyph-density depth**,  
**turn-based control**, and **frame-based ASCII animations**.

The demo scene is a separate program using this engine.

---

## Engine Goals
- ASCII-only rendering (no color dependency)
- Visual depth via glyph density
- Turn-based update model
- Frame-based animation system
- Same rendering path for gameplay and cutscenes

---

## Engine Non-Goals
- Real-time physics or timing
- Game-specific logic
- UI frameworks or menus
- Asset pipelines
- Cross-platform terminal abstraction (initially)

---

## ENGINE TODO

### Project Structure
- [ ] Create `/engine` directory
- [ ] Define public headers (`engine/`)
- [ ] Keep engine independent from demo logic
- [ ] No hardcoded scene content in engine

---

### Core Types
- [ ] `FrameBuffer` (glyph + light/intensity)
- [ ] `GlyphRamp` (intensity → ASCII)
- [ ] `Renderer`
- [ ] `Animation`
- [ ] `AnimationPlayer`

---

### FrameBuffer
- [ ] Fixed-size 2D buffers
- [ ] Light/intensity buffer (`uint8_t` or `float`)
- [ ] Glyph buffer (`char`)
- [ ] Clear/reset functions

---

### Glyph Ramp & Depth
- [ ] Define default glyph ramp (dark → light)
- [ ] Implement `intensity_to_glyph()`
- [ ] Support custom ramps
- [ ] Enforce foreground > midground > background contrast

---

### Renderer
- [ ] Clear framebuffer per frame
- [ ] Draw primitives:
  - [ ] point
  - [ ] rectangle
- [ ] Apply lighting/intensity
- [ ] Convert light buffer → glyph buffer
- [ ] Output full frame via ANSI
- [ ] Cursor control (hide/show, move)

---

### Animation System
- [ ] `AnimationFrame` (per-frame light overrides + duration)
- [ ] `Animation` (ordered frames)
- [ ] Blocking animation playback
- [ ] No input during animation
- [ ] Re-render each frame using renderer

---

### Turn-Based Model
- [ ] Explicit `begin_turn()` / `end_turn()`
- [ ] No internal real-time loop
- [ ] All updates driven by caller
- [ ] Engine remains deterministic

---

### Input Handling (Minimal)
- [ ] Raw key read (WASD)
- [ ] Blocking input
- [ ] Engine exposes input hooks, not logic

---

### Cutscene Support
- [ ] Cutscene = animation sequence
- [ ] Same pipeline as normal rendering
- [ ] No special-casing
- [ ] Engine does not own story logic

---

### Engine Constraints
- [ ] ASCII only
- [ ] No color dependency
- [ ] No scene knowledge
- [ ] No globals tied to demo state

---

## DEMO TODO (SEPARATE)

### Project Setup
- [ ] Create `/demo` directory
- [ ] Link against engine
- [ ] Define fixed screen size
- [ ] Initialize renderer and buffers

---

### Demo Scene
- [ ] Hardcoded map
- [ ] Player start position
- [ ] Exit tile
- [ ] Depth rules per tile
- [ ] Simple environment animation

---

### Demo Logic
- [ ] WASD movement
- [ ] Turn counter
- [ ] Trigger animations per turn
- [ ] Block movement with walls

---

### Demo Cutscenes
- [ ] Start cutscene using engine animations
- [ ] End cutscene using engine animations
- [ ] Lock input during playback

---

### Demo Constraints
- [ ] One scene only
- [ ] No extra systems
- [ ] Visual-first, not mechanic-first

---

## Completion Criteria

### Engine
- Rendering produces visible depth without color
- Animations and cutscenes share the same pipeline
- Turn-based model is enforced
- Engine usable without demo

### Demo
- Clearly showcases engine capabilities
- Turn-based input feels deliberate
- Animations enhance atmosphere
- Clean start → end execution
