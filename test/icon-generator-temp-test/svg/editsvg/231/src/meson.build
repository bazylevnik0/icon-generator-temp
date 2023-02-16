icon_generator_temp_test_editsvg_sources = [
  'main.c',
  'icon_generator_temp_test_editsvg-window.c',
  'icon_generator_temp_test_editsvg-application.c',
]

icon_generator_temp_test_editsvg_deps = [
  dependency('libadwaita-1', version: '>= 1.0'),
]

gnome = import('gnome')

icon_generator_temp_test_editsvg_sources += gnome.compile_resources('icon_generator_temp_test_editsvg-resources',
  'icon_generator_temp_test_editsvg.gresource.xml',
  c_name: 'icon_generator_temp_test_editsvg'
)

executable('icon-generator-temp-test-editsvg', icon_generator_temp_test_editsvg_sources,
  dependencies: icon_generator_temp_test_editsvg_deps,
  install: true,
)
