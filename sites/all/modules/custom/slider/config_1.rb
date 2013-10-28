/* 960 Grid System ~ Core CSS.
 * Learn more ~ http://960.gs/
 * *
 * Licensed under GPL and MIT. */

@import "compass/reset";

// The following generates the default grids provided by the css version of 960.gs
.container_12 {
  @include grid-system(12);
}

.container_16 {
  @include grid-system(16);
}

// But most compass users prefer to construct semantic layouts like so (two column layout with header and footer):

$ninesixty-columns: 24;

.two-column {
  @include grid-container;
  #header, #footer {
    @include grid(24);
  }
  #sidebar {
    @include grid(8);
  }
  #main-content {
    @include grid(16);
  }
}