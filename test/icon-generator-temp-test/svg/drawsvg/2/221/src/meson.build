image_generator_temp_test_svg_sources = [
  'main.c',
  'image_generator_temp_test_svg-window.c',
  'image_generator_temp_test_svg-application.c',
]

image_generator_temp_test_svg_deps = [
  dependency('libadwaita-1', version: '>= 1.0'),
]

gnome = import('gnome')

image_generator_temp_test_svg_sources += gnome.compile_resources('image_generator_temp_test_svg-resources',
  'image_generator_temp_test_svg.gresource.xml',
  c_name: 'image_generator_temp_test_svg'
)

executable('image-generator-temp-test-svg', image_generator_temp_test_svg_sources,
  dependencies: image_generator_temp_test_svg_deps,
  install: true,
)
