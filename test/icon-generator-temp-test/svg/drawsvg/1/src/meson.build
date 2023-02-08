icon_generator_temp_test_svg_sources = [
  'main.c',
  'icon_generator_temp_test_svg-window.c',
  'icon_generator_temp_test_svg-application.c',
]

icon_generator_temp_test_svg_deps = [
  dependency('libadwaita-1', version: '>= 1.0'),
]

gnome = import('gnome')

icon_generator_temp_test_svg_sources += gnome.compile_resources('icon_generator_temp_test_svg-resources',
  'icon_generator_temp_test_svg.gresource.xml',
  c_name: 'icon_generator_temp_test_svg'
)

executable('icon-generator-temp-test-svg', icon_generator_temp_test_svg_sources,
  dependencies: icon_generator_temp_test_svg_deps,
  install: true,
)
