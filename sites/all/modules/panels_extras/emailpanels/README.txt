Panels Extras: Email CCK Field and Panels 3 Integration

DESCRIPTION
-----------

Email CCK Field and Panels 3 Integration exposes the CCK Email (http://drupal.org/project/email) field to Panels. The field can be formatted as a clickable email address or a link to a contact form.

REQUIREMENTS
------------

Panels Extras requires Panels and CTools. Email CCK Field and Panels 3 Integration requires the Email module to be installed also.

INSTALLATION
------------

1. Copy the entire panels_extras directory to Drupal's sites/all/modules directory.
2. Login as an administrator and enable the Email CCK Field and Panels 3 Integration module listed in the Panels Extras section.


USAGE
-----

1. Enable "contactemail" in Site building > Pages (admin/build/pages) to provide the contact form under the path email/%node/%field_name.
2. Add at least one variant and add Panels Extras Widget "CCK Email Contact form" to its content
3. Go to your panel (Usually Node Template) where you want to include the email contact form link and add the node > field_{email}; set the formatter to "Email contact form".