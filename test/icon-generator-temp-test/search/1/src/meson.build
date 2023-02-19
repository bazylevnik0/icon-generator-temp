icon_generator_temp_test_search_sources = [
  'main.c',
  'icon_generator_temp_test_search-window.c',
  'icon_generator_temp_test_search-application.c',
]

icon_generator_temp_test_search_deps = [
  dependency('libadwaita-1', version: '>= 1.0'),
]

gnome = import('gnome')

icon_generator_temp_test_search_sources += gnome.compile_resources('icon_generator_temp_test_search-resources',
  'icon_generator_temp_test_search.gresource.xml',
  c_name: 'icon_generator_temp_test_search'
)

executable('icon-generator-temp-test-search', icon_generator_temp_test_search_sources,
  dependencies: icon_generator_temp_test_search_deps,
  install: true,
)
